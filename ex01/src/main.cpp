/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:48 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/31 12:16:54 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main()
{
    std::cout << "\n=== TESTING CONSTRUCTORS ===\n" << std::endl;
    
    // Test default constructor
    ScavTrap defaultTrap;
    std::cout << "Default ScavTrap created - Name: " << defaultTrap.getName() 
              << ", HP: " << defaultTrap.getHitpoints() 
              << ", Energy: " << defaultTrap.getEnergyPoints() 
              << ", Attack damage: " << defaultTrap.getAttackDamage() << std::endl;
    
    // Test parameterized constructor
    ScavTrap scavTrap("SC4V-TP");
    
    // Test copy constructor
    ScavTrap scavCopy(scavTrap);
    std::cout << "Copy created - Name: " << scavCopy.getName() << std::endl;
    
    std::cout << "\n=== TESTING FUNCTIONALITY ===\n" << std::endl;
    
    // Test attack function (overridden)
    scavTrap.attack("Bandit");
    
    // Test inherited functions
    scavTrap.takeDamage(25);
    scavTrap.beRepaired(10);
    
    // Test unique ScavTrap ability
    scavTrap.guardGate();
    scavTrap.guardGate(); // Should indicate already in Gate keeper mode
    
    std::cout << "\n=== TESTING ENERGY DEPLETION ===\n" << std::endl;
    
    // Create ScavTrap for energy testing (50 energy points)
    ScavTrap energyTest("EnergyTester");
    
    // Attack to deplete energy
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0)
            std::cout << "Attack attempt " << (i + 1) << ": ";
        energyTest.attack("Target");
        if (i % 10 == 9)
            std::cout << std::endl;
    }
    
    // Try actions with no energy
    std::cout << "\nAttempting actions with no energy:" << std::endl;
    energyTest.attack("Enemy");
    energyTest.beRepaired(10);
    energyTest.guardGate();
    
    std::cout << "\n=== TESTING LETHAL DAMAGE ===\n" << std::endl;
    
    // Create ScavTrap for damage testing
    ScavTrap defender("Defender");
    
    // Deal lethal damage
    defender.takeDamage(150);
    
    // Try actions while dead
    defender.attack("Someone");
    defender.beRepaired(10);
    defender.guardGate();
    
    std::cout << "\n=== COMPARING WITH BASE CLASS ===\n" << std::endl;
    
    // Create a ClapTrap for comparison
    ClapTrap clapTrap("Original");
    clapTrap.attack("Target");
    
    // Show ScavTrap's enhanced attack
    scavTrap.attack("Same Target");
    
    std::cout << "\nEnd of tests - objects will be destroyed" << std::endl;
    
    return (0);
}
