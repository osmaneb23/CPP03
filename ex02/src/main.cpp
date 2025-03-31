/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:48 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/31 11:25:33 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main()
{
    std::cout << "\n=== TESTING CONSTRUCTORS ===\n" << std::endl;
    
    // Test default constructor
    ScavTrap defaultTrap;
    
    // Test parameterized constructor
    ScavTrap scavTrap1("SC4V-TP");
    
    // Test copy constructor
    ScavTrap scavTrap2(scavTrap1);
    
    std::cout << "\n=== TESTING BASIC FUNCTIONALITY ===\n" << std::endl;
    
    // Test attack function (ScavTrap version)
    scavTrap1.attack("Bandit");
    
    // Test takeDamage function (inherited from ClapTrap)
    scavTrap1.takeDamage(30);
    
    // Test beRepaired function (inherited from ClapTrap)
    scavTrap1.beRepaired(15);
    
    // Test unique ScavTrap ability
    scavTrap1.guardGate();
    scavTrap1.guardGate(); // Test calling guardGate twice
    
    std::cout << "\n=== TESTING COPY CONSTRUCTOR AND ASSIGNMENT ===\n" << std::endl;
    
    ScavTrap original("Original");
    original.takeDamage(20);
    original.attack("Target");
    
    std::cout << "\nCreating a copy with copy constructor:" << std::endl;
    ScavTrap copy(original);
    
    std::cout << "\nTesting assignment operator:" << std::endl;
    ScavTrap assignTarget("AssignTarget");
    assignTarget = original;
    
    std::cout << "\n=== TESTING ENERGY DEPLETION ===\n" << std::endl;
    
    // Create new ScavTrap for energy testing (50 energy points)
    ScavTrap energyTest("EnergyTest");
    
    // Attack multiple times to deplete energy
    for (int i = 0; i < 51; i++) {
        if (i % 10 == 0)
            std::cout << "Attack attempt " << (i + 1) << ": ";
        energyTest.attack("Target Dummy");
        if (i % 10 == 9)
            std::cout << std::endl;
    }
    
    // Try actions with no energy
    std::cout << "\nAttempting actions with no energy:" << std::endl;
    energyTest.attack("Enemy");
    energyTest.beRepaired(10);
    energyTest.guardGate();
    
    std::cout << "\n=== TESTING LETHAL DAMAGE ===\n" << std::endl;
    
    // Create a new ScavTrap for damage testing
    ScavTrap defender("Defender");
    
    // Deal a lot of damage
    defender.takeDamage(150);
    
    // Try actions while dead
    defender.attack("Someone");
    defender.beRepaired(10);
    defender.guardGate();
    
    return (0);
}
