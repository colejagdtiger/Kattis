import fractions

C = fractions.Fraction(input())
C *= fractions.Fraction('5/9')
C -= fractions.Fraction('160/9')
print(f'{C.numerator}/{C.denominator}')


