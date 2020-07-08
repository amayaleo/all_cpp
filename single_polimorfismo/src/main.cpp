#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
class Persona {
  public:
   Persona(const char *n) { strcpy(nombre, n); }
   
   Persona(const Persona &p);
   
   virtual void VerNombre() 
   { 
      cout << nombre << "Persona::VerNombre()"<< endl; 
   }
   
   virtual Persona* Clonar() 
   {       	     
	   std::cout << "\t virtual Persona* Clonar() class Persona" << std::endl;
	   return new Persona(*this); 
	}
  protected:
   char nombre[30];
};

Persona::Persona(const Persona &p) 
{
   strcpy(nombre, p.nombre);
	std::cout << "\tcopia - Persona(const Persona &p) -  name : " << p.nombre<< std::endl;
}

class Empleado : public Persona 
{
  public:
   Empleado(const char *n) : Persona(n) {std::cout << "\tEmpleado()" << std::endl;}
   
   Empleado(const Empleado &e);
   
   void VerNombre() 
   { 
      cout << "Emp : " << nombre <<"Empleado::VerNombre()"<< endl; 
   }
   virtual Persona* Clonar() 
   { 
	     std::cout << "\t virtual Persona* Clonar() of class Empleado" << std::endl;
	   return new Empleado(*this); 
	}
};

Empleado::Empleado(const Empleado &e) : Persona(e) 
{
   cout << "\t Empleado(const Empleado &e) : Persona(e)" << endl;
}

class Estudiante : public Persona {
  public:
   Estudiante(const char *n) : Persona(n) {std::cout << "\tEstudiante()" << std::endl;}
   Estudiante(const Estudiante &e);
   void VerNombre() { 
      cout << "Est: " << nombre <<" - Estudiante::VerNombre()"<< endl; 
   }
   virtual Persona* Clonar() { 
	   	     std::cout << "\t virtual Persona* Clonar() of class Estudiante" << std::endl;

      return new Estudiante(*this); 
   }
};

Estudiante::Estudiante(const Estudiante &e) : Persona(e) {
   cout << "\t Estudiante(const Estudiante &e) : Persona(e)" << endl;
}

int main() {

Persona * Estudiante_tmp = new Estudiante("Estudiante");
Persona * Empleado_tmp = new Empleado("Empleado");
Persona * Gente[2];
std::vector <Persona> People;
People.push_back("s");
People.push_back("t");
auto& r = People.emplace_back(Estudiante("student - "));


r.Clonar();
r.VerNombre();
std::cout <<"****************************\n";

    Estudiante_tmp->VerNombre();
    Empleado_tmp->VerNombre();

    std::cout <<"****************************\n";

    		Gente[0] = Estudiante_tmp->Clonar();
    		Gente[0]->VerNombre();

    std::cout <<"****************************\n";

	    	Gente[1] = Empleado_tmp->Clonar();
    		Gente[1]->VerNombre();

 std::cout <<"****************************\n";




delete Estudiante_tmp;
delete Empleado_tmp;
delete Gente[0];
delete Gente[1];
   return 0;
}


// #include <iostream>

// struct Derive
// {
// 	Derive()
// 		: variable{0}
// 	{
// 		std::cout << " Derive()  : " << variable << "\n";
// 	}

// 	~Derive() { std::cout << "~Derive()  : " << variable << "\n"; }
// 	void set(Derive tmp)
// 	{
// 		variable = tmp.variable;
// 	}

// 	void get()
// 	{
// 		std::cout << "Derive get() " << variable << "\n";
// 	};

// 	int variable;
// };

// struct Herency
// {
// 	virtual ~Herency() = default;
// 	virtual void set(Derive) = 0;
// 	virtual void get() = 0;
// };

// struct HijoA : public Herency
// {
// 	HijoA()
// 		: variable{0}
// 	{
// 		std::cout << "HijoA()  " << variable << "\n";
// 	}
// 	~HijoA() { std::cout << " ~HijoA()  " << variable << "\n"; }
// 	void set(Derive tmp) override
// 	{
// 		variable = tmp.variable;
// 		std::cout << "  B set -> variable : " << variable << "\n";
// 	}

// 	void get() override
// 	{
// 		std::cout << "B +  A get : " << variable << "\n";
// 	};

// 	int variable;
// };

// struct HijoB : public Herency
// {
// 	HijoB()
// 		: variable{0}
// 	{
// 		std::cout << "HijoB() : " << variable << "\n";
// 	}
// 	~HijoB() { std::cout << "~HijoB() : " << variable << "\n"; }
// 	void set(Derive tmp) override
// 	{
// 		variable = tmp.variable;
// 		std::cout << "  C set -> variable : " << variable << "\n";
// 	}

// 	void get() override
// 	{
// 		std::cout << "C get() - variable : " << variable << "\n";
// 	};
// 	int variable;
// };

// int main()
// {
// 	Herency * a = new HijoA();
// 	auto &p_a = *a;
// 	HijoA b;
// 	HijoB c;
// 	Derive d;
// 	Herency &e = *a;

// 	d.variable = 4;

// 	p_a.set(d);

// 	e.get();

// 	d.variable = 7;

// 	e.set(d);

// 	d.variable = 8;

// 	c.set(d);

// 	a->get();

// 	a->set(d);

// 	e.get();

// 	while (1);

// 	delete a;

// 	return 0;
// }
