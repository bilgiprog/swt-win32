@set Zip=C:\Progs\7-Zip\7z.exe
@del src.zip
%Zip% a src.zip org\ -xr!*.class
@del ..\swt-4.7-win32-win32-x86_64.zip
%Zip% a ..\swt-4.7-win32-win32-x86_64.zip about.html about_files\ .classpath .project src.zip swt.jar swt-debug.jar
@pause