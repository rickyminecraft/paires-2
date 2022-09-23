#include "Fichier.h"

Fichier::Fichier()
{
	if (!PHYSFS_init(nullptr))
	{
		Report_error("Impossible d'initialiser PHYSFS");
	}
	else
	{
		//on monte le fichier zip
		Mount(Pak_name);
	}
}

Fichier::~Fichier()
{
	//si on charge une ou des fontes de caractère, il faut libérer la mémoire ici.
	for (short Boucle = 0; Boucle < Buffer_fonte.size(); ++Boucle)
	{
		delete Buffer_fonte[Boucle];
	}
	PHYSFS_deinit();
}

const bool Fichier::Has_error() const
{
	return bError;
}

const sf::String Fichier::Get_error() const
{
	if (stError.size() != 0)
	{
		sf::String Text = stError[stError.size() - 1];
		stError.pop_back();
		return Text;
	}
	bError = false;
	return "";
}

void Fichier::Mount(const sf::String File_name)
{
	if (!PHYSFS_mount(File_name.toAnsiString().c_str(), "", 1))
	{
		Report_error(PHYSFS_getLastError());
	}
}

void Fichier::Report_error(const sf::String Error_string)
{
	bError = true;
	stError.push_back(Error_string);
}

const bool Fichier::File_exist(const sf::String File_name)
{
	if (PHYSFS_exists(File_name.toAnsiString().c_str()))
	{
		return true;
	}
	else
	{
		sf::String Error_text = "Fichier non trouvé: " + File_name;
		Report_error(Error_text);
		return false;
	}
}
