#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person
{
	string name;
	int score;

	void print()
	{
		cout << name << " " << score << "\n";
	}
};

void swap(vector<Person>& v, int i, int j) {
	Person temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int partition(vector<Person>& v, int low, int high) {
	Person pivot = v[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (v[j].score < pivot.score)
		{
			swap(v, i, j);
			i++;
		}
		else if (v[j].score == pivot.score)
		{
			int equalOrNot = v[j].name.compare(pivot.name);
			if (equalOrNot > 0)
			{
				swap(v, i, j);
				i++;
			}
		}
	}

	swap(v, i, high);
	return i;
}


void quickSort(vector<Person>& v, int low, int high) 
{
	if (low < high) 
	{
		int partitionIndex = partition(v, low, high);

		quickSort(v, low, partitionIndex - 1);
		quickSort(v, partitionIndex + 1, high);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<string> names;
	vector<int> scores;
	vector<Person> people;

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		names.push_back(name);
	}

	for (int i = 0; i < N; i++)
	{
		int score;
		cin >> score;
		scores.push_back(score);
	}

	for (int i = 0; i < N; i++)
	{
		Person person;
		person.name = names[i];
		person.score = scores[i];

		people.push_back(person);
	}

	quickSort(people, 0, people.size() - 1);

	for (int i = N - 1; i >= 0; i--)
	{
		people[i].print();
	}
}