#Simple Market Model

a = float(input("Enter a: "))
b = float(input("Enter b: "))
c = float(input("Enter c: "))
d = float(input("Enter d: "))

p = (a-c)/(b+d);
D = a - (b*p);
S = c + (d*p);

if D == S:
  print("Equilibrium point: (" + str(D) + " , " + str(p) + ")")
  print("\nQuantity Q = " + str(D))
  print("Price P = " + str(p))

else:
  print("There is no Equilibrium point")