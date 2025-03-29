/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:48 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/29 17:14:24 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
    std::cout << "\n=== TESTING CONSTRUCTORS ===\n" << std::endl;
    
    // Test default constructor
    ClapTrap defaultTrap;
    
    // Test parameterized constructor
    ClapTrap claptrap1("CL4P-TP");
    
    // Test copy constructor
    ClapTrap claptrap2(claptrap1);
    
    // Test assignment operator
    ClapTrap claptrap3;
    claptrap3 = claptrap1;
    
    std::cout << "\n=== TESTING BASIC FUNCTIONALITY ===\n" << std::endl;
    
    // Test attack function
    claptrap1.attack("Bandit");
    
    // Test takeDamage function
    claptrap1.takeDamage(3);
    
    // Test beRepaired function
    claptrap1.beRepaired(2);
    
    std::cout << "\n=== TESTING ENERGY DEPLETION ===\n" << std::endl;
    
    // Attack multiple times to deplete energy
    for (int i = 0; i < 10; i++) {
        std::cout << "Attack attempt " << (i + 1) << ": ";
        claptrap2.attack("Target Dummy");
    }
    
    // Try to repair with no energy
    std::cout << "\nAttempting to repair with no energy:" << std::endl;
    claptrap2.beRepaired(5);
    
    std::cout << "\n=== TESTING LETHAL DAMAGE ===\n" << std::endl;
    
    // Deal lethal damage
    std::cout << "Dealing lethal damage:" << std::endl;
    claptrap3.takeDamage(20);
    
    // Try actions while dead
    std::cout << "\nAttempting actions while 'dead':" << std::endl;
    claptrap3.attack("Someone");
    claptrap3.beRepaired(10);
    claptrap3.takeDamage(5);
    
    std::cout << "\n=== TESTING CHAIN ATTACKS ===\n" << std::endl;
    
    // Create a fresh ClapTrap for this test
    ClapTrap fighter("Fighter");
    
    // Attack, take damage, repair cycle
    fighter.attack("Enemy1");
    fighter.takeDamage(4);
    fighter.beRepaired(2);
    fighter.attack("Enemy2");
    fighter.takeDamage(5);
    fighter.beRepaired(1);
    
    return (0);
}

