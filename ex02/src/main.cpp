/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:48 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/31 12:18:59 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main()
{
    std::cout << "\n=== TESTING FRAGTRAP CONSTRUCTORS ===\n" << std::endl;
    
    // Test default constructor
    FragTrap defaultTrap;
    std::cout << "Default FragTrap created - Name: " << defaultTrap.getName() 
              << ", HP: " << defaultTrap.getHitpoints() 
              << ", Energy: " << defaultTrap.getEnergyPoints() 
              << ", Attack damage: " << defaultTrap.getAttackDamage() << std::endl;
    
    // Test parameterized constructor
    FragTrap fragTrap1("FR4G-TP");
    
    // Test copy constructor
    FragTrap fragTrap2(fragTrap1);
    
    std::cout << "\n=== TESTING BASIC FUNCTIONALITY ===\n" << std::endl;
    
    // Test inherited attack function
    fragTrap1.attack("Skag");
    
    // Test takeDamage function (inherited from ClapTrap)
    fragTrap1.takeDamage(40);
    std::cout << "After taking damage - HP: " << fragTrap1.getHitpoints() << std::endl;
    
    // Test beRepaired function (inherited from ClapTrap)
    fragTrap1.beRepaired(20);
    std::cout << "After repair - HP: " << fragTrap1.getHitpoints() 
              << ", Energy: " << fragTrap1.getEnergyPoints() << std::endl;
    
    // Test unique FragTrap ability
    fragTrap1.highFivesGuys();
    
    std::cout << "\n=== TESTING ENERGY DEPLETION ===\n" << std::endl;
    
    // Create new FragTrap for energy testing (100 energy points)
    FragTrap energyTest("EnergyTest");
    
    // Attack multiple times to deplete energy
    for (int i = 0; i < 101; i++) {
        if (i % 20 == 0)
            std::cout << "Attack attempt " << (i + 1) << ": ";
        energyTest.attack("Target Dummy");
        if (i % 20 == 19)
            std::cout << std::endl;
    }
    
    // Try actions with no energy
    std::cout << "\nAttempting actions with no energy:" << std::endl;
    energyTest.attack("Enemy");
    energyTest.beRepaired(10);
    energyTest.highFivesGuys();
    
    std::cout << "\n=== TESTING LETHAL DAMAGE ===\n" << std::endl;
    
    // Create a new FragTrap for damage testing
    FragTrap defender("Defender");
    
    // Deal a lot of damage
    defender.takeDamage(150);
    
    // Try actions while dead
    defender.attack("Someone");
    defender.beRepaired(10);
    defender.highFivesGuys();
    
    std::cout << "\n=== DEMONSTRATING DESTRUCTION ORDER ===\n" << std::endl;
    
    // Create a scope to demonstrate destruction order
    {
        std::cout << "Creating a new FragTrap inside a scope:" << std::endl;
        FragTrap scopeTrap("ScopeTrap");
        std::cout << "About to exit scope - watch destruction order:" << std::endl;
    } // FragTrap destructor should be called first, then ClapTrap destructor
    
    std::cout << "\nMain function about to end - remaining objects will be destroyed." << std::endl;
    
    return (0);
}
