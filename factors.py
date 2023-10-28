def factorize(n):
    for i in range(2, n):
        if n % i == 0:
            return f"{n}={i}*{n//i}"
    return f"{n} is prime"

if __name__ == "__main__":
    with open("input.txt", "r") as file:
        for line in file:
            n = int(line)
            result = factorize(n)
            print(result)
