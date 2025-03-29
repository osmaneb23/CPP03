/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:48 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/29 18:42:14 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main()
{
    std::cout << "\n=== TESTING CONSTRUCTORS ===\n" << std::endl;
    
    // Test default constructor
    ScavTrap defaultTrap;
    
    // Test parameterized constructor
    ScavTrap scavtrap1("SC4V-TP");
    
    // Test copy constructor - with explicit checking
    std::cout << "\n--> Testing copy constructor:" << std::endl;
    ScavTrap scavtrap2(scavtrap1);
    
    // Test assignment operator - with explicit checking
    std::cout << "\n--> Testing assignment operator:" << std::endl;
    ScavTrap scavtrap3;
    scavtrap3 = scavtrap1;
    
    std::cout << "\n=== TESTING BASIC FUNCTIONALITY ===\n" << std::endl;
    
    // Test attack function - note this uses ScavTrap's version
    scavtrap1.attack("Bandit");
    
    // Test takeDamage function - inherited from ClapTrap
    scavtrap1.takeDamage(30);
    
    // Test beRepaired function - inherited from ClapTrap
    scavtrap1.beRepaired(15);
    
    // Test guardGate() - successful use
    std::cout << "\n--> Testing Gate keeper mode:" << std::endl;
    scavtrap1.guardGate();
    
    // Test guardGate() - already guarding case
    std::cout << "\n--> Testing Gate keeper mode while already guarding:" << std::endl;
    scavtrap1.guardGate();
    
    std::cout << "\n=== TESTING ENERGY DEPLETION ===\n" << std::endl;
    
    // Create a new ScavTrap for energy tests
    ScavTrap energyTester("EnergyTest");
    
    // Attack multiple times to deplete energy
    std::cout << "Depleting energy with attacks:" << std::endl;
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0)
            std::cout << "Attack attempt " << (i + 1) << ": ";
        energyTester.attack("Target Dummy");
        if (i % 10 == 9)
            std::cout << std::endl;
    }
    
    // Try actions with no energy
    std::cout << "\n--> Testing actions with no energy:" << std::endl;
    energyTester.attack("Enemy");
    energyTester.beRepaired(5);
    energyTester.guardGate();
    
    std::cout << "\n=== TESTING LETHAL DAMAGE ===\n" << std::endl;
    
    // Create a new ScavTrap for damage testing
    ScavTrap defender("Defender");
    
    // Deal a lot of damage
    std::cout << "--> Dealing massive damage:" << std::endl;
    defender.takeDamage(150);
    
    // Try actions while dead
    std::cout << "\n--> Testing actions while dead:" << std::endl;
    defender.attack("Someone");
    defender.beRepaired(10);
    defender.guardGate();
    
    return (0);
}

