Building SWT for win32-x64 from source drops at http://download.eclipse.org/eclipse/downloads/
using Visual Studio 2017 Community and a couple very simple cmd scripts.
1. Open the solution _swt-win32.sln_, set JAVA_HOME in custom property sheet, then build the solution. Dll artifacts
should appear in `java` folder.
1. `cd` to java folder,
1. Run `make-jar.cmd` (check %JAVA_HOME%)
1. Run `make-zip.cmd` (check %Zip%)
1. final zip artifact should appear in solution dir.

Release section also has the final zip artifact with ControlExample and CustomControlExample as standalone runnable jars.

---

_http://download.eclipse.org/eclipse/downloads/ adresinden dağıtılan SWT paketinin Visual Studio 2017 Community ve
bir çift cmd script ile win32-x64 için build edilmesi._

1. _VS içinden swt-win32.sln seçerek açın, property manager'dan x86Sheet içindeki JAVA_HOME makrosunu kendinize
uyacak şekilde ayarlayın, sonra build. `java` klasörü altında .dll dosyalar oluşacak._
1. _`java` klasörüne geçin_
1. _`make-jar.cmd` çalıştırın (%JAVA_HOME% ayarladıktan sonra)_
1. _`make-zip.cmd` çalıştırın (%Zip% ayarladıktan sonra)_
1. _tepe klasörde nihai zip dosyası oluşacaktır._

_Release kısmında bağımsız çalışabilen ControlExample ve CustomControlExample örnekleri ve nihai zip dosyası mevcuttur._
