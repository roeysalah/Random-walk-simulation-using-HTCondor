

import matplotlib.pyplot as plt
from collections import Counter


def read_coordinates(file_path):
    with open(file_path, 'r') as file:
        return [float(line.strip()) for line in file if line.strip()]


def plot_histogram(coordinates):
    frequency = Counter(coordinates)
    values, counts = zip(*frequency.items())

    plt.figure(figsize=(10, 5))
    plt.bar(values, counts, color='green')  # Change color here
    plt.xlabel('Coordinate Value')
    plt.ylabel('Frequency')
    plt.title('Histogram of Coordinate Frequencies')
    plt.grid(True)
    plt.show()


def main():
    file_path = 'out.txt'
    coordinates = read_coordinates(file_path)
    plot_histogram(coordinates)


if __name__ == "__main__":
    main()
