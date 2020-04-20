#include<iostream>
#include<map>

class Login
{
public:
    std::map<int,std::string> m_userdata;

	void Login_in(int id)
	{
         auto it = m_userdata.find(id);
         std::string username;
         if(it != m_userdata.end())
         {
         	std::cout<<"***Please enter the user name ****"<<std::endl;
         	std::cin>>username;
         	if(it->second != username)
         	{
         		///Log error
         	}
         	else
         	{
         		std::cout<<"User : "<<it->first<<" successfully logged in "<<std::endl;
         	}

         }

         else 
         {
         	std::cout<<it->first<<": Not found in the DB please register"<<std::endl;
         	Register(id);
         }
	}

	void Register(int id)
	{
		std::string username;
		std::cout<<"Plese enter the name for the id : "<<id<<"  to register"<<std::endl;
		std::cin>>username;
		m_userdata.insert(std::make_pair(id,username));
        auto m_itr = m_userdata.find(id);
        if(m_itr != m_userdata.end())
        {
        	std::cout<<"User with user id : "<<m_itr->first<<" and User name : "<<m_itr->second <<" registered successfully "<<std::endl;

        }
		
	}
};

int main()
{
	int ch;
	int id;
	Login *l_obj = new Login();
	l_obj->m_userdata.insert(std::make_pair(1054789,"Nara"));
	l_obj->m_userdata.insert(std::make_pair(489136,"Shrisd"));
	l_obj->m_userdata.insert(std::make_pair(7894561,"Sara"));
  
	std::cout<<"Enter 1 to login and 2 to register"<<std::endl;
	std::cin>>ch;

	switch(ch)
	{
		case 1 : std::cout<<"Enter the user id "<<std::endl;
                 std::cin>>id;
                 l_obj->Login_in(id);
                 break;
        case 2 : std::cout<<"Enter the id to register "<<std::endl;
                 std::cin>>id;
                 l_obj->Register(id);
                 break;
        default : std::cout<<"Enter the appropriate option "<<std::endl;

	}
}

