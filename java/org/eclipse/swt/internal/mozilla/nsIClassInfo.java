/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code, released March 31, 1998.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by Netscape are Copyright (C) 1998-1999
 * Netscape Communications Corporation.  All Rights Reserved.
 *
 * Contributor(s):
 *
 * IBM
 * -  Binding to permit interfacing between Mozilla and SWT
 * -  Copyright (C) 2003, 2012 IBM Corp.  All Rights Reserved.
 *
 * ***** END LICENSE BLOCK ***** */
package org.eclipse.swt.internal.mozilla;


public class nsIClassInfo extends nsISupports {

	static final int LAST_METHOD_ID = nsISupports.LAST_METHOD_ID + 8;

	static final String NS_ICLASSINFO_IID_STR = "986c11d0-f340-11d4-9075-0010a4e73d9a";

	static {
		IIDStore.RegisterIID(nsIClassInfo.class, MozillaVersion.VERSION_BASE, new nsID(NS_ICLASSINFO_IID_STR));
	}

	public nsIClassInfo(long /*int*/ address) {
		super(address);
	}

	public static final int SINGLETON = 1;
	public static final int THREADSAFE = 2;
	public static final int MAIN_THREAD_ONLY = 4;
	public static final int DOM_OBJECT = 8;
	public static final int PLUGIN_OBJECT = 16;
	public static final int EAGER_CLASSINFO = 32;
	public static final int CONTENT_NODE = 64;
//	public static final int RESERVED = 2147483648;
}
