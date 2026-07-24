import numpy as np

class Dual:
    """Número dual a + b·d con d^2 = 0.

    Atributos:
        value : parte real, valor f(x).
        deriv : parte dual, valor f'(x).
    """

    def __init__(self, value, deriv):
        self.value = value
        self.deriv = deriv

    def __add__(self, other):
        return Dual(self.value + other.value, self.deriv + other.deriv)

    def __sub__(self, other):
        return Dual(self.value - other.value, self.deriv - other.deriv)

    def __mul__(self, other):
        return Dual(self.value * other.value, (self.value * other.deriv) + (self.deriv * other.value))

    def __truediv__(self, other):
        return Dual (self.value / other.value, ((self.deriv * other.value)-(self.value*other.deriv))/(other.value**2))


def sin(d):
    return Dual(np.sin(d.value), d.deriv * np.cos(d.value))

def cos(d):
    return Dual(np.cos(d.value), -d.deriv * np.sin(d.value) )


def exp(d):
    return Dual(np.exp(d.value), d.deriv * np.exp(d.value))


if __name__ == "__main__":
    x0 = 0.5
    x = Dual(x0,1)
    dual2 = Dual(2,0)
    
    dual2x = dual2 * x
    dual_sin2x = sin(dual2x)
    result = exp(dual_sin2x)
    
    print("\nPARTE B")
    print(f"f({x0}) = {result.value}")
    print(f"f'({x0}) = {result.deriv}")
    
    f = lambda x: np.exp(np.sin(2*x))
    df = lambda x: 2*np.cos(2*x)*np.exp(np.sin(2*x))
    
    f_x = f(x0)
    df_x = df(x0)

    err_fx = np.abs(result.value - f_x)
    err_dfx = np.abs(result.deriv - df_x)
    
    print("\nPARTE C")
    print(f"f_dual({x0}) = {result.value}. f({x0}) = {f_x}. Error Absoluto: {err_fx}")
    print(f"f'_dual({x0}) = {result.deriv}. f'({x0}) = {df_x}. Error Absoluto: {err_dfx}\n")