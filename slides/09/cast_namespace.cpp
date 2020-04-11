#include <iostream>

class Awards
{
protected:
	virtual ~Awards() {}
};

class DogAwards :public Awards
{
public:
	//DogAwards() : name(18) {}
	int name = 10;
protected:
	virtual ~DogAwards() {}
};

class CatAwards : public Awards
{
public:
	//std::string name = "Alisa";
	int name = 22;
};

int main()
{
	DogAwards *pd = new DogAwards();
	CatAwards *pc = new CatAwards();
	Awards* aw;
	std::cout << pc->name << std::endl;
	std::cout << pd->name << std::endl;
	aw = dynamic_cast<Awards*>(pd);
	pc = dynamic_cast<CatAwards*>(aw);
	if (pc)
		std::cout << pc->name << std::endl;
	else
		std::cout << "Unable to convert" << std::endl;
	//delete pd;
}

