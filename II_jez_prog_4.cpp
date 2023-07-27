#include <iostream>
#include <string>

using namespace std;

class Index;
class Grade
{
	friend class Index;

private:
	string subject;
	float grade;

public:
	Grade(string subjectin = "UNKNOWN", float gradein = 0) : subject(subjectin), grade(gradein){};
	void Show() { cout << subject << ": " << grade << endl; }
	void SetSubject(string subjectin) { subject = subjectin; }
	void SetGrade(float gradein)
	{
		if ((gradein == 2.0) || (gradein == 2.5) || (gradein == 3.0) || (gradein == 3.5) || (gradein == 4.0) || (gradein == 4.5) || (gradein == 5.0))
			grade = gradein;
	}
	string GetSubject() { return subject; }
	float GetGrade() { return grade; }
};
class GradeBook
{
private:
	int ngrades;
	Grade *grades;

public:
	GradeBook(int ngradesin) : ngrades(gradesin) { grades = new Grade[ngrades]; }
	~GradeBook() { delete[] grades; }
	void Set(int i, string subjectin, float gradein)
	{
		if ((i >= 0) && (i <= ngrades - 1))
		{
			grades[i].subject = subjectin;
			grades[i].SetGrade(gradein);
		}
	}

	void Change(string subjectin, float gradein)
	{
		for (int i = 0; i < ngrades; i++)
			if (grades[i].GetSubject() == subjectin)
				grades[i].SetGrade(gradein);
	}

	float Average()
	{
		if (ngrades == 0)
			return 0;
		float sum = 0.0;
		for (int i = 0; i < ngrades; i++)
			sum += grades[i].grade;
		return sum / ngrades;
	}
	void Show()
	{
		cout << "----Book of Grades---- " << endl;
		for (int i = 0; i < ngrades; i++)
		{
			grades[i].Show();
		}
		cout << "Average= " << Average() << endl;
	}
	void Add(string subjectin, float gradein);
	void Remove(string subjectin);
	friend float FindGrade(GradeBook *gradebookin, string subjectin);
};

void GradeBook::Add(string subjectin, float gradein)
{
	Grade *temp = new Grade[ngrades + 1];

	for (int i = 0; i < ngrades; i++)
	{
		temp[i] = grades[i];
	}
	delete[] grades;
	grades = temp;
	grades[ngrades].SetSubject(subjectin);
	grades[ngrades].SetGrade(gradein);
	ngrades++;
}

void GradeBook::Remove(string subjectin)
{
	int pos = -1;
	for (int i = 0; i < ngrades; i++)
	{
		if (grade[i].GetSubject() == subjectin)
			pos = i;
	}
	if (pos == -1)
		return;
	Grade *temp = new Grade[ngrades - 1];
	for (int i = 0; i < pos; i++)
		temp[i] = grades[i];
	for (int i = pos + 1; i < ngrades; i++)
		temp[i - 1] = grades[i];
	delete[] grades;
	grades = temp;
	ngrades--;
}
float FindGrade(GradeBook *gradebookin, string subjectin)
{
	for (int i = 0; i < gradebookin->ngrades; i++)
	{
		if (gradebookin->grades[i].GetSubject() == subjectin)
		{
			return gradebookin->grades[i].GetGrade();
		}
	}
}

int main()
{
	GradeBook ind(3);
	ind.Set(0, "Analysis", 3);
	ind.Set(1, "Algebra", 4);
	ind.Set(2, "Physics", 4);
	ind.Show();
	cout << "algebra's grade: " << FindGrade(&ind, "Algebra") << endl;
	ind.Change("Algebra", 5);
	ind.Show();
	ind.Add("C++ Programming", 5);
	ind.Show();
	ind.Remove("Physics");
	ind.Show();
	return 0;
}
