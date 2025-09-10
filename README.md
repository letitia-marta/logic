# Propositional Formula Validator 📘

This project implements a **C++ program** that checks whether a given input string represents a valid **propositional logic formula**.  

Symbols used for logical operators:  
- `&` → ∧ (AND)  
- `/` → ∨ (OR)  
- `|` → ¬ (NOT)  
- `-` → ⇒ (IMPLIES)  
- `_` → ⇔ (EQUIVALENT)  

Input is read from `date.in` and results are written to `date.out`.

## 📁 Project Structure

```
│
├── date.in
├── date.out
└── formula_propozitionala.cpp
```

## 📝 Program Description

The program validates whether the input string is:  
- ✅ **Atomic proposition** (single uppercase letter like `A`, `B`, …)  
- ✅ **Well-formed propositional formula** (respects logical syntax and parentheses)  
- ❌ **Not a valid formula** (if it violates logical syntax rules)

Validation rules include:  
- Balanced parentheses.  
- Proper use of connectors (no consecutive connectors, no connector right before a closing parenthesis, etc.).  
- Atomic propositions cannot appear directly adjacent (e.g., `AB` is invalid).  
- Negations `|` must be used correctly.  
- No empty parentheses `()` allowed.  

## ⚙️ How It Works

1. **Input parsing**  
   - The program reads characters one by one into a buffer.  

2. **Validation checks**  
   - Counts parentheses and connectors.  
   - Applies syntactic rules to detect invalid sequences.  

3. **Output**  
   - If valid: `"Este formula propozitionala."`  
   - If atomic: `"Este propozitie atomica."`  
   - If invalid: `"Nu este formula propozitionala."`  
