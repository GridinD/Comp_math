import matplotlib.pyplot as plt
import numpy as np

n = int(input("Введите количество точек: "))

x = []
y = []

for i in range(n):
    xi = float(input(f"Введите x[{i}]: "))
    yi = float(input(f"Введите y[{i}]: "))
    x.append(xi)
    y.append(yi)


def lagrange(x, y, t):
    n = len(x)
    L = np.zeros(n)
    for i in range(n):
        xi = x[i]
        yi = y[i]
        l = 1
        for j in range(n):
            if i != j:
                xj = x[j]
                l *= (t - xj) / (xi - xj)
        L[i] = yi * l
    return np.sum(L)

t = float(input("Введите точку, в которой нужно вычислить значение полинома: "))
y_interp = lagrange(x, y, t)

print(f"Значение интерполяционного полинома в точке {t}: {y_interp}")

t_interp = np.linspace(x[0], x[n-1], 101)
y_interp_all = np.zeros(len(t_interp))
for i in range(len(t_interp)):
    y_interp_all[i] = lagrange(x, y, t_interp[i])

plt.plot(t_interp, y_interp_all, label='Интерполяционный полином Лангранжа')
plt.plot(x, y, 'ro', label='Узлы интерполяции')
plt.plot(t, y_interp, 'bo', label='Запрашиваемая точка')
plt.legend()
plt.show()