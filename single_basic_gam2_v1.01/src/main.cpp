#include <iostream>
#include <algorithm>
#include <cstdint>
#include <memory>
#include <vector>


namespace ECS
{
	struct Component_t
	{
	};

	struct Sprite_t
	{
	};

	struct Entity_t
	{
	private:
		std::unordered_map<std::size_t , Component_t*> components; //ver STL unordered_map es una template
	    inline static std::size_t nextTypeID{ 0 };
	public:
	explicit Entity_t() = default;

        template<typename TYPE>
	static  std::size_t  getComponentTypeID()
        {
               static std::size_t type { ++ nextTypeID };
	        return type ;
       }

	template<typename CMP_t>
	void addComponent(CMP_t& cmp) // Agregar componentes //pero solo son validos el agredado del tipo Component_t + Entitiy_t
	{
		auto type = getComponentTypeID<CMP_t>(); //el programa pasa 2 veces por aqui

 		components[type] = &cmp;
	}


	template<typename CMP_t>
	CMP_t* getComponent()
	{
		//el programa pasa dos veces por aqui

		auto type = getComponentTypeID<CMP_t>();
		auto it = components.find(type);
		if( it!= components.end() )
		{
			return static_cast<CMP_t*>(it->second);
		}
		return nullptr;
	}



	template <typename CMP_t>
	const CMP_t* getComponent()const
	{
		// el programa pasa 2 veces por aqui

		auto p = const_cast<Entity_t*>(this)->getComponent<CMP_t>();
		return const_cast<const CMP_t*>(p);
	}

	};

}//end ECS


	template<typename TYPE>
	struct RenderComponent_t : ECS::Component_t
	{
		TYPE x,y;
		char sp;
	};


	void cls(){std::puts("\033[H\033[J");}

	void locate (uint8_t x , uint8_t y ){std::printf("\033[%d;%dH",y,x);}

	template <typename TYPE>
	void draw(const ECS::Entity_t& e)
	{
		auto* r = e.template getComponent<TYPE>();

		if( r )
		{
	//		locate(r->x,r->y);
	//		std::putchar(r->sp);
		}
	}

int main()
{

	std::vector<ECS::Entity_t>entities;// entities es un vector del tipo Entitiy_t
	entities.reserve(10);
	auto& player = entities.emplace_back(); //Player es un objeto del tipo Entity_t
	auto& entities_2  = entities.emplace_back();
	RenderComponent_t<uint16_t> render_component 	{ { } , 6 , 3 , 'x' }; // el primer "{}" se le pasa un parametro vacio devido a que existe para completar la estructura "Component_t"
	player.addComponent ( render_component );//render_component es un componente del tipo RenderComponent_t 
	
	RenderComponent_t<uint16_t> render_component2 { { } , 20, 10 ,'@' };
	entities_2.addComponent (  render_component2 );
	cls(); 

	// for_each : recorre el vector de entities , ejecuta el contenido de draw
	std::for_each( entities.begin() , entities.end() , draw<RenderComponent_t<uint16_t>>);
	int i=5;
	while ( i--){
	std::cout<< std::endl;
}
	

  return 0;
}
