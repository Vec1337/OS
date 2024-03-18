# 1.c

Napisati program koji ispisuje -1 ili 1 slučajno na ekran. Program neka koristi jedno polje char tipa veličine 100000 znakova. Polje deklarirati globalno izvan tijela glavne (main()) funkcije. Program neka prvo to polje popuni brojem -1 ili 1, a nakon toga ispiše to polje na ekran (znakove iz polja). 

# 2.c

Napisati program koji naredbom fork() stvara nove procese djecu. Proces roditelj u programu mora stvoriti 10, 100, 1000, 10000 i 100000 procesa djece. Neka se broj procesa djece unosi kao parametar komandne linije prilikom poziva programa. Proces dijete u programu ispisuje niz „Dijete #n“ gdje je n broj procesa djeteta (indeks petlje), te nakon toga završava sa radom. Proces roditelj u nastavku rada prije stvaranja novog procesa djeteta (unutar for petlje) ispisuje  „Roditelj #n“ gdje je n broj procesa djeteta (indeks petlje).