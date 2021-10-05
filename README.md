# Chuviks
## roadmap

- lage et c program som kan løse en rubiks kube fra enhver start posisjon
- optimilisere programmet til å kunne løse rubiks kuben effektivt
- programmet outputter hvilke moves som må til for å løse kuben i et format som kan "parses" av en arudiono
  Eks:
  r2, l, u, ......, hvor r står for høyre servo motor f.eks.
- arduino styrer servo motorer som løser kuben
- arduino har sensorer som kan finne ut av startposisjonen til kuben
- så integrere alt i et continuous program

## flow
### ARDUINO
- bruker lys og evt. farge sensor til å finne start pos. til rubiks kube
- starte programmet som løser en kube med start posisjonen som argument
### C programmet
- løser kuben
- lager en output som er en serie med "moves" som skal utføres for å løse kuben
### ARDUINO
- leser og "parser" outputen fra C programmet
- utløser instruksjonene fra outputen og styrer servo motorer som løser kuben.
- voila

Logo: https://www.freelogodesign.org/manager/showcase/9a507fc0bd3742859223c8b157ff9db9
