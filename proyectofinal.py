def mayor_y_menor(nums):
    mayor_y_menor = [nums[0], nums[0]]

    for num in nums[1:]:
        if num < mayor_y_menor[0]:
            mayor_y_menor[0] = num

        if num > mayor_y_menor[1]:
            mayor_y_menor[1] = num

    return mayor_y_menor

def promedio_sin_extremos(nums):
    extremos = mayor_y_menor(nums)
    return (sum(nums) - extremos[0] - extremos[1]) / (len(nums) - 2)

def main():
    numeros = [float(input(f"Ingrese el valor #{i + 1}: ")) for i in range(5)]

    extremos = mayor_y_menor(numeros)
    print("Cotizaciones eliminadas:")
    for extremo in extremos:
        print(extremo)

    promedio = promedio_sin_extremos(numeros)
    print(f"Promedio: {promedio}")

if __name__ == "__main__":
    main()
