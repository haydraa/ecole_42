#ifndef IMateriaSource
#define IMateriaSource

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void LearnMateria(AMateria*) = 0;
		virtual AMateria* CreateMateria(std::string const & type) = 0;
};


#endif
