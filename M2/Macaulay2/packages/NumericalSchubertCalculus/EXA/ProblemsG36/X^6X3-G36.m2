needsPackage "NumericalSchubertCalculus"
setRandomSeed 2

--Problem X^6X3 in G(3,6)
 --a problem with 5 solutions
SchPblm = randomSchubertProblemInstance(
  {{3},{1},{1},{1},{1},{1},{1}},3,6);
time S = solveSchubertProblem(SchPblm, 3,6);
assert all(S,s->checkIncidenceSolution(s, SchPblm))

 end
 ------

