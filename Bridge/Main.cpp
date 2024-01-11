#include <iostream>
using namespace std;


class IDevice abstract
{
public:
	virtual void Show() abstract;
};

class Videocard : public IDevice 
{
private:
	string name;
	string model;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	void SetModel(string model)
	{
		this->model = model;
	}
	string GetName()
	{
		return name;
	}
	string GetModel()
	{
		return model;
	}
	void Show() override {
		cout << "Videocard: " << name << ' ' << model << endl;
	}
};

class Processor : public IDevice
{
private:
	string name;
	string model;
	double frequency;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	void SetModel(string model)
	{
		this->model = model;
	}
	void SetFrequency(double frequency) 
	{
		this->frequency = frequency;
	}
	string GetName() 
	{
		return name;
	}
	string GetModel()
	{
		return model;
	}
	double GetFrequency() 
	{
		return frequency;
	}
	void Show() override 
	{
		cout << "Processor: " << name << ' ' << model << "\nFrequency: " << frequency << endl;
	}
};

class HDD : public IDevice 
{
private:
	string name;
	string model;
	int volume;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	void SetModel(string model)
	{
		this->model = model;
	}
	void SetVolume(int volume) 
	{
		this->volume = volume;
	}
	string GetName()
	{
		return name;
	}
	string GetModel()
	{
		return model;
	}
	int GetVolume() 
	{
		return volume;
	}
	void Show() override 
	{
		cout << "HDD: " << name << ' ' << model << "\nVolume: " << volume << " GB" << endl;
	}
};

class RAM : public IDevice
{
private:
	string name;
	string model;
	int volume;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	void SetModel(string model) 
	{
		this->model = model;
	}
	void SetVolume(int volume) 
	{
		this->volume = volume;
	}
	string GetName()
	{
		return name;
	}
	string GetModel() 
	{
		return model;
	}
	int GetVolume() 
	{
		return volume;
	}
	void Show() override 
	{
		cout << "RAM: " << name << ' ' << model << "\nVolume: " << volume << " GB" << endl;
	}

};

class Library
{
protected:
	IDevice* device;
public:
	IDevice* GetDevice()
	{
		return device;
	}
	void SetDevice(IDevice* device)
	{
		this->device = device;
	}
	virtual void Show()
	{
		device->Show();
	}
};

void Client(IDevice* device, Library* library)
{
	library->SetDevice(device);
	library->Show();
}

int main()
{
	Library* library = new Library();

	Videocard* videocard = new Videocard();
	videocard->SetName("Asus");
	videocard->SetModel("RX 6600");
	library->SetDevice(videocard);
	library->Show();

	Processor* processor = new Processor();
	processor->SetName("Intel");
	processor->SetModel("I7");
	processor->SetFrequency(4);
	library->SetDevice(processor);
	library->Show();

	HDD* hdd = new HDD();
	hdd->SetName("Transcend StoreJet ");
	hdd->SetModel("TRNI4539043");
	hdd->SetVolume(2000);
	library->SetDevice(hdd);
	library->Show();

	RAM* ram = new RAM();
	ram->SetName("Kingston Fury");
	ram->SetModel("TS2TSJ25M3G");
	ram->SetVolume(8);
	library->SetDevice(ram);
	library->Show();

	delete videocard;
	delete processor;
	delete hdd;
	delete ram;
	delete library;

	return 0;
}