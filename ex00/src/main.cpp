/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:48 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/29 19:55:03 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
    std::cout << "\n=== TESTING CONSTRUCTORS ===\n" << std::endl;
    
    // Test default constructor
    ClapTrap defaultTrap;
    std::cout << "Default ClapTrap created - Name: " << defaultTrap.getName() << ", HP: " << defaultTrap.getHitpoints() 
              << ", Energy: " << defaultTrap.getEnergyPoints() << ", Attack damage: " << defaultTrap.getAttackDamage() << std::endl;
    
    // Test parameterized constructor
    ClapTrap claptrap1("CL4P-TP");
    std::cout << "Named ClapTrap created - Name: " << claptrap1.getName() << ", HP: " << claptrap1.getHitpoints() 
              << ", Energy: " << claptrap1.getEnergyPoints() << ", Attack damage: " << claptrap1.getAttackDamage() << std::endl;
    
    // Test copy constructor
    ClapTrap claptrap2(claptrap1);
    std::cout << "Copied ClapTrap created - Name: " << claptrap2.getName() << ", HP: " << claptrap2.getHitpoints() 
              << ", Energy: " << claptrap2.getEnergyPoints() << ", Attack damage: " << claptrap2.getAttackDamage() << std::endl;
    
    std::cout << "\n=== TESTING COPY CONSTRUCTOR ===\n" << std::endl;
    
    // Create an original with some changes to its state
    ClapTrap original("Original");
    std::cout << "Original before changes - Name: " << original.getName() << ", HP: " << original.getHitpoints() 
              << ", Energy: " << original.getEnergyPoints() << std::endl;
    
    original.attack("Target");
    std::cout << "After attack - Energy: " << original.getEnergyPoints() << std::endl;
    
    original.takeDamage(3);
    std::cout << "After damage - HP: " << original.getHitpoints() << std::endl;
    
    original.beRepaired(1);
    std::cout << "After repair - HP: " << original.getHitpoints() << ", Energy: " << original.getEnergyPoints() << std::endl;
    
    // Create a copy and test if it has the same state
    std::cout << "\nCreating a copy with copy constructor:" << std::endl;
    ClapTrap copy(original);
    std::cout << "Copy stats - Name: " << copy.getName() << ", HP: " << copy.getHitpoints() 
              << ", Energy: " << copy.getEnergyPoints() << std::endl;
    
    copy.takeDamage(2);
    std::cout << "Copy after damage - HP: " << copy.getHitpoints() << std::endl;
    
    copy.beRepaired(1);
    std::cout << "Copy after repair - HP: " << copy.getHitpoints() << ", Energy: " << copy.getEnergyPoints() << std::endl;
    
    // Show original is unchanged by copy's actions
    std::cout << "\nOriginal should still have its own state:" << std::endl;
    std::cout << "Original stats - Name: " << original.getName() << ", HP: " << original.getHitpoints() 
              << ", Energy: " << original.getEnergyPoints() << std::endl;
    
    std::cout << "\n=== TESTING ASSIGNMENT OPERATOR ===\n" << std::endl;
    
    // Create new traps to test assignment
    ClapTrap assignTarget("AssignTarget");
    std::cout << "AssignTarget initial - Name: " << assignTarget.getName() << ", HP: " << assignTarget.getHitpoints() 
              << ", Energy: " << assignTarget.getEnergyPoints() << std::endl;
    
    assignTarget.attack("Dummy");
    assignTarget.takeDamage(1);
    std::cout << "AssignTarget after changes - HP: " << assignTarget.getHitpoints() 
              << ", Energy: " << assignTarget.getEnergyPoints() << std::endl;
    
    ClapTrap assignSource("AssignSource");
    std::cout << "AssignSource initial - Name: " << assignSource.getName() << ", HP: " << assignSource.getHitpoints() 
              << ", Energy: " << assignSource.getEnergyPoints() << std::endl;
    
    std::cout << "\nPerforming assignment: assignSource = assignTarget" << std::endl;
    assignSource = assignTarget;
    std::cout << "AssignSource after assignment - Name: " << assignSource.getName() << ", HP: " << assignSource.getHitpoints() 
              << ", Energy: " << assignSource.getEnergyPoints() << std::endl;
    
    std::cout << "\nModifying AssignSource to ensure they're independent:" << std::endl;
    assignSource.takeDamage(3);
    std::cout << "AssignSource after damage - HP: " << assignSource.getHitpoints() << std::endl;
    
    std::cout << "AssignTarget should be unchanged - HP: " << assignTarget.getHitpoints() 
              << ", Energy: " << assignTarget.getEnergyPoints() << std::endl;
    
    std::cout << "\n=== TESTING BASIC FUNCTIONALITY ===\n" << std::endl;
    
    // Reset for clean testing
    ClapTrap functional("Functional");
    std::cout << "Initial stats - HP: " << functional.getHitpoints() 
              << ", Energy: " << functional.getEnergyPoints() << std::endl;
    
    // Test attack function
    functional.attack("Bandit");
    std::cout << "After attack - Energy: " << functional.getEnergyPoints() << std::endl;
    
    // Test takeDamage function
    functional.takeDamage(3);
    std::cout << "After damage - HP: " << functional.getHitpoints() << std::endl;
    
    // Test beRepaired function
    functional.beRepaired(2);
    std::cout << "After repair - HP: " << functional.getHitpoints() 
              << ", Energy: " << functional.getEnergyPoints() << std::endl;
    
    std::cout << "\n=== TESTING ENERGY DEPLETION ===\n" << std::endl;
    
    ClapTrap energyTest("EnergyTest");
    std::cout << "Initial energy: " << energyTest.getEnergyPoints() << std::endl;
    
    // Attack multiple times to deplete energy
    for (int i = 0; i < 10; i++) {
        std::cout << "Attack attempt " << (i + 1) << ": ";
        energyTest.attack("Target Dummy");
        std::cout << "Remaining energy: " << energyTest.getEnergyPoints() << std::endl;
    }
    
    // Try to attack with no energy
    std::cout << "\nAttempting to attack with no energy:" << std::endl;
    energyTest.attack("Target Dummy");
    
    // Try to repair with no energy
    std::cout << std::endl;
    energyTest.takeDamage(5);
    std::cout << "\nAttempting to repair with no energy:" << std::endl;
    energyTest.beRepaired(5);
    std::cout << "HP after repair attempt: " << energyTest.getHitpoints() << std::endl;
    
    std::cout << "\n=== TESTING LETHAL DAMAGE ===\n" << std::endl;
    
    ClapTrap mortal("Mortal");
    std::cout << "Initial HP: " << mortal.getHitpoints() << std::endl;
    
    // Taking lethal damage
    std::cout << "Taking lethal damage:" << std::endl;
    mortal.takeDamage(20);
    std::cout << "HP after lethal damage: " << mortal.getHitpoints() << std::endl;
    
    // Try actions while dead
    std::cout << "\nAttempting actions while 'dead':" << std::endl;
    mortal.attack("Someone");
    mortal.beRepaired(10);
    std::cout << "HP after repair attempt: " << mortal.getHitpoints() << std::endl;
    mortal.takeDamage(5);
    std::cout << "HP after additional damage: " << mortal.getHitpoints() << std::endl;
    
    return (0);
}

