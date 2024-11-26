import matplotlib.pyplot as plt

# 데이터 읽기
results = {}
current_size = None

with open("data/results.txt", "r") as file:
    for line in file:
        line = line.strip()
        if line.startswith("Dataset size:"):
            current_size = int(line.split(":")[1].strip())
        else:
            algorithm, time = line.split(" ")
            time = float(time)
            if algorithm not in results:
                results[algorithm] = []
            results[algorithm].append((current_size, time))

# 데이터셋 크기별로 정렬
for algorithm in results:
    results[algorithm].sort(key=lambda x: x[0])

# 그래프 생성
for algorithm, data in results.items():
    sizes, times = zip(*data)
    plt.plot(sizes, times, label=algorithm)

plt.title("Sorting Algorithm Performance_12201884")
plt.xlabel("Dataset Size")
plt.ylabel("Execution Time (ms)")
plt.legend()
plt.grid()
plt.show()
