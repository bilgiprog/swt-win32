@set JAVA_HOME=C:\Progs\Java\jdk1.8.0_131
%JAVA_HOME%\bin\javac.exe @clist.txt
%JAVA_HOME%\bin\jar.exe cfm swt.jar jarmanifest.txt @mlist.txt
%JAVA_HOME%\bin\javac.exe -g @clist.txt
%JAVA_HOME%\bin\jar.exe cfm swt-debug.jar jarmanifest.txt @mlist.txt
@pause