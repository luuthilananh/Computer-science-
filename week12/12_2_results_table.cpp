#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ResultsTable
{
private:
    vector<unsigned int> scores;

public:
    void addResult(unsigned int score)
    {
        scores.push_back(score);
    }

    unsigned int getMinScore() const
    {
        if (scores.empty())
            return 0;

        return *min_element(scores.begin(), scores.end());
    }

    unsigned int getScoreForPosition(unsigned int positionNumber) const
    {
        if (scores.empty())
            return 0;

        // Сортируем результаты в убывающем порядке
        vector<unsigned int> sortedScores = scores;
        sort(sortedScores.begin(), sortedScores.end(), greater<unsigned int>());

        // Получаем баллы для данной позиции
        unsigned int positionScore = sortedScores[positionNumber - 1];

        // Проверяем, есть ли игроки с одинаковыми баллами
        for (unsigned int i = positionNumber; i < sortedScores.size(); ++i)
        {
            if (sortedScores[i] == positionScore)
                positionScore = sortedScores[i];
            else
                break;
        }

        return positionScore;
    }
};

int main()
{
    ResultsTable t;
    t.addResult(42);
    t.addResult(42);
    t.addResult(42);
    //t.addResult(31);

    cout << "1st place score: " << t.getScoreForPosition(1) << endl;
    cout << "2nd place score: " << t.getScoreForPosition(2) << endl;
    cout << "3rd place score: " << t.getScoreForPosition(3) << endl;
    cout << "Min score during the tournament: " << t.getMinScore() << endl;

    return 0;
}
