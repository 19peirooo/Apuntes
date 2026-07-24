def calc_EPS():
    x = 1.0
    while 100.0 + x != 100.0:
        x /= 2
    EPS = 2.0 * x
    print(f"EPS = {EPS}")
    print(f"x = {x}")

def main():
    # mantisa = 6 digitos
    r = 6
    num1 = 0.987624687925
    num2 = 0.987624
    b = 90
    L = -7
    U = 8
    res = num1 - num2


if __name__ == "__main__":
    main()
