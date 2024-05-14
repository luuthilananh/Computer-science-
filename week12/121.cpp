#include <iostream>
#include <vector>

using namespace std;

class Task
{
protected:
    int cpuNum;
    int size;

public:
    Task(int cpuNum, int size)
    {
        this->cpuNum = cpuNum;
        this->size = size;
    }

    int getCPU() const
    {
        return cpuNum;
    }

    int getSize() const
    {
        return size;
    }
};

class Analyzer
{
private:
    vector<int> coreLoads;

public:
    Analyzer(int numCores)
    {
        coreLoads.resize(numCores, 0);
    }

    void analyze(const vector<Task> &tasks)
    {
        // Сбрасываем нагрузку на ядрах перед каждым анализом
        fill(coreLoads.begin(), coreLoads.end(), 0);

        for (const Task &task : tasks)
        {
            int cpuNum = task.getCPU();
            int size = task.getSize();
            // Увеличиваем нагрузку на соответствующем ядре
            coreLoads[cpuNum] += size;
        }
    }

    int getLoadForCPU(int cpuNum)
    {
        // Возвращаем нагрузку на заданном ядре
        return coreLoads[cpuNum];
    }
};

int main()
{
    int numberOfCores = 4;
    vector<Task> data = {{0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5}};
    Analyzer a(numberOfCores);
    a.analyze(data);
    for (int i = 0; i < numberOfCores; i++)
        cout << a.getLoadForCPU(i) << endl;

    return 0;
}
