#ifndef ALL_CLASSES_H
#define ALL_CLASSES_H

// Ingredient.h
// Class representing an ingredient used in recipes
#include <string>

class Ingredient {
private:
    int ingredient_id;
    std::string name;
    float quantity;
    std::string unit;

public:
    std::string getDetails() const;
    void adjustQuantity(float new_quantity);
};


// Recipe.h
// Class representing a recipe with ingredients and cooking details
#include <vector>
#include <string>

class Ingredient; // Forward declaration

class Recipe {
private:
    int recipe_id;
    std::string name;
    std::vector<Ingredient> ingredients;
    int cooking_time; // In minutes
    std::string dietary_type;

public:
    void prepareRecipe();
    std::vector<Ingredient> getIngredients() const;
    std::string getCookingInstructions() const;
};


// MealPrepKit.h
// Class representing a meal prep kit with recipes and pricing
#include <vector>
#include <string>

class Recipe; // Forward declaration

class MealPrepKit {
private:
    int kit_id;
    std::string name;
    float price;
    std::string dietary_preference;
    std::vector<Recipe> recipes;

public:
    void addRecipe(const Recipe& recipe);
    void removeRecipe(const Recipe& recipe);
    std::vector<Recipe> getRecipes() const;
};


// Subscription.h
// Class representing a subscription to meal prep kits
#include <vector>
#include <string>

class User; // Forward declaration
class MealPrepKit; // Forward declaration

class Subscription {
private:
    int subscription_id;
    User* user; // Pointer to avoid incomplete type issues
    std::string startDate;
    std::string endDate;
    std::vector<MealPrepKit> kits;

public:
    void renewSubscription();
    void cancelSubscription();
    std::vector<MealPrepKit> getActiveKits() const;
};


// User.h
// Class representing a user of the meal prep service
#include <string>

class User {
private:
    int user_id;
    std::string name;
    std::string email;
    std::string address;

public:
    void subscribe();
    void updateProfile();
};


// Delivery.h
// Class representing a delivery of a meal prep kit to a user
#include <string>

class MealPrepKit; // Forward declaration
class User; // Forward declaration

class Delivery {
private:
    int delivery_id;
    std::string deliveryDate;
    std::string status;
    MealPrepKit* kit; // Pointer to avoid incomplete type issues
    User* user; // Pointer to avoid incomplete type issues

public:
    void scheduleDelivery();
    void trackDelivery();
    void confirmDelivery();
};


// NutritionInfo.h
// Class representing nutritional information of a meal
#include <vector>

class Recipe; // Forward declaration

class NutritionInfo {
private:
    float calories;
    float protein;
    float fat;
    float carbs;

public:
    // Method to calculate total nutrition
    static NutritionInfo calculateTotalNutrition(const std::vector<Recipe>& recipes);
};


// Payment.h
// Class representing a payment transaction
class Payment {
private:
    int payment_id;             // Unique identifier for the payment
    std::string name;          // Name of the payer
    float amount;              // Amount of the payment
    std::string date;          // Date of the payment
    User* user;                // Pointer to the user making the payment
    std::string status;        // Status of the payment (e.g., processed, refunded)

public:
    // Process the payment
    void processPayment();

    // Refund the payment
    void refundPayment();

    // Get the status of the payment
    std::string getPaymentStatus() const;
};


#endif // ALL_CLASSES_H
