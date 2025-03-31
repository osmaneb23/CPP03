/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:48 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/31 12:02:56 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main()
{
    std::cout << "\n=== TESTING DIAMONDTRAP CONSTRUCTORS ===\n" << std::endl;
    
    // Test default constructor
    DiamondTrap defaultTrap;
    std::cout << "Default DiamondTrap stats:"
              << "\n - Hitpoints: " << defaultTrap.getHitpoints()       // From FragTrap (100)
              << "\n - Energy: " << defaultTrap.getEnergyPoints()       // From ScavTrap (50)
              << "\n - Attack damage: " << defaultTrap.getAttackDamage() // From FragTrap (30)
              << std::endl;
    
    // Test parameterized constructor
    DiamondTrap diamond("Diamond");
    
    // Test copy constructor
    DiamondTrap diamondCopy(diamond);
    
    std::cout << "\n=== TESTING NAME SHADOWING ===\n" << std::endl;
    
    // Test the whoAmI function to demonstrate name shadowing
    diamond.whoAmI();  // Should show both names (Diamond and Diamond_clap_name)
    
    std::cout << "\n=== TESTING INHERITED ABILITIES ===\n" << std::endl;
    
    // Test inherited attack from ScavTrap
    diamond.attack("Target");  // Should use ScavTrap's version
    
    // Test guardGate from ScavTrap
    diamond.guardGate();
    
    // Test highFivesGuys from FragTrap
    diamond.highFivesGuys();
    
    std::cout << "\n=== TESTING OBJECT STATE ===\n" << std::endl;
    
    // Test taking damage
    diamond.takeDamage(30);
    
    // Test repairing
    diamond.beRepaired(15);
    
    std::cout << "\n=== TESTING ENERGY DEPLETION ===\n" << std::endl;
    
    // Create new DiamondTrap for energy testing (has ScavTrap's 50 energy points)
    DiamondTrap energyTest("EnergyTester");
    
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
    energyTest.highFivesGuys();
    
    std::cout << "\n=== TESTING LETHAL DAMAGE ===\n" << std::endl;
    
    // Create a new DiamondTrap for damage testing
    DiamondTrap defender("Defender");
    
    // Deal a lot of damage
    defender.takeDamage(150);
    
    // Try actions while dead
    defender.attack("Someone");
    defender.beRepaired(10);
    defender.guardGate();
    defender.highFivesGuys();
    defender.whoAmI();
    
    std::cout << "\n=== DEMONSTRATING DESTRUCTION ORDER ===\n" << std::endl;
    
    // Create a scope to demonstrate destruction order
    {
        std::cout << "Creating a new DiamondTrap inside a scope:" << std::endl;
        DiamondTrap scopeTrap("ScopeTrap");
        std::cout << "About to exit scope - watch destruction order:" << std::endl;
    } // Destruction order should be: DiamondTrap, FragTrap, ScavTrap, ClapTrap
    
    std::cout << "\nMain function about to end - remaining objects will be destroyed." << std::endl;
    
    return (0);
}
