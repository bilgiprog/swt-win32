/*******************************************************************************
* Copyright (c) 2000, 2016 IBM Corporation and others.
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*    IBM Corporation - initial API and implementation
*******************************************************************************/

#include "swt.h"
#include "jawt_md.h"

#define SWT_AWT_NATIVE(func) Java_org_eclipse_swt_awt_SWT_1AWT_##func

#ifndef NO_getAWTHandle
JNIEXPORT jintLong JNICALL SWT_AWT_NATIVE(getAWTHandle)
(JNIEnv *env, jclass that, jobject canvas)
{
	JAWT awt;
	JAWT_DrawingSurface* ds;
	JAWT_DrawingSurfaceInfo* dsi;
	JAWT_Win32DrawingSurfaceInfo* dsi_win;
	jintLong result = 0;
	jint lock;

	awt.version = JAWT_VERSION_1_3;
	if (JAWT_GetAWT(env, &awt) != 0) {
		ds = awt.GetDrawingSurface(env, canvas);
		if (ds != NULL) {
			lock = ds->Lock(ds);
			if ((lock & JAWT_LOCK_ERROR) == 0) {
				dsi = ds->GetDrawingSurfaceInfo(ds);
				dsi_win = (JAWT_Win32DrawingSurfaceInfo*)dsi->platformInfo;
				result = (jintLong)dsi_win->hwnd;
				ds->FreeDrawingSurfaceInfo(dsi);
				ds->Unlock(ds);
			}
		}
		awt.FreeDrawingSurface(ds);
	}
	return result;
}
#endif

#ifndef NO_initFrame
JNIEXPORT jobject JNICALL SWT_AWT_NATIVE(initFrame)
(JNIEnv *env, jclass that, jintLong handle, jstring className)
{
	jobject object;
	jmethodID constructor;

	jclass cls = (*env)->FindClass(env, "sun/awt/windows/WEmbeddedFrame");
	if (NULL == cls) return NULL;
	constructor = (*env)->GetMethodID(env, cls, "<init>", "(J)V");
	object = (*env)->NewObject(env, cls, constructor, handle);
	return object;
}
#endif

#ifndef NO_synthesizeWindowActivation
JNIEXPORT void JNICALL SWT_AWT_NATIVE(synthesizeWindowActivation)
(JNIEnv *env, jclass that, jobject frame, jboolean doActivate)
{
	jmethodID midInit;
	jclass cls = (*env)->FindClass(env, "sun/awt/windows/WEmbeddedFrame");
	if (NULL == cls) return;
	midInit = (*env)->GetMethodID(env, cls, "synthesizeWindowActivation", "(Z)V");
	(*env)->CallVoidMethod(env, frame, midInit, doActivate);
}
#endif
