## Problema 1

Pentru a observa daca un graf are cicluri s-a folosit algoritmul DFS. Acesta a fost modificat ca atunci cand se gaseste un nod "gri" in timpul parcurgerii se iese din algoritm si se returneaza ca graful contine un ciclu. Daca nu se gaseste nici un ciclu, algoritmul se efectueaza complet si se returneaza ca nu exista nici un ciclu.

## Problema 2

Pentru a calcula distantele minime se foloseste sortarea topologica. Nodurile se parcurg in ordinea determinata si in cazul in care distanta curenta este mai mica decat aceasta se actualizeaza.

## Problema 3

Pentru a rezolva aceasta problema am folosit algoritmul Dijkstra cu o lista de prioritati pentru a selecta urmatorul nod cu distanta minima.