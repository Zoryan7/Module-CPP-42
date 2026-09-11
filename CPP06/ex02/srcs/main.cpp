/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoumene <ymoumene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:42:39 by ymoumene          #+#    #+#             */
/*   Updated: 2026/07/19 13:28:37 by ymoumene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

static bool is_seeded = false;

Base * generate(void)
{
    if (!is_seeded)
    {
        srand(time(NULL));
        is_seeded = true;
    }
    int random = rand() % 3;
    
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p) )
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Base";
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A\n";
        return;
    }
    catch(std::exception &bc)
    {}    
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;        
        std::cout << "B\n";
        return;
    }
    catch (std::exception &bc)
    {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C\n";
        return;
    }
    catch (std::exception &bc)
    {
        std::cout << "conversion impossible beacause of : " << bc.what();
    }    
}

int main(void)
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return (0);
}
