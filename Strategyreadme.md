Water Auction Strategy Bot (C++)
📌 Overview

This project implements an automated bidding strategy for a 20-round water auction survival game.

Each round:

Players bid for limited water supply.

Water affects health.

Players earn salary each round.

If a player doesn’t get water, their no_water_days increases.

Too many no-water days → health drops → risk of elimination.

The goal of this bot:

Survive all 20 rounds while managing balance efficiently and outbidding competitors only when necessary.

🧠 Strategy Logic Explained

The bot dynamically adjusts its bid based on:

✅ Current round number

✅ Health level

✅ Number of consecutive no-water days

✅ Current balance

✅ Salary

✅ Previous round’s average bids

✅ Randomness (to avoid predictability)

🎮 Game Phases Strategy

The 20 rounds are divided into phases:

🔹 Phase 1: Early Game (Rounds 1–8)

Goal: Conserve money while staying healthy.

If health is high (>7):

Bid conservatively.

Usually around:

0.5 × salary + small random value

If player missed water:

Increase aggression slightly.

Bid 40%–60% of balance randomly.

If health drops to medium (5–7):

More aggressive bidding.

Uses:

max(balance %, 1.5 × previous average bids)

If health ≤ 3:

Bid full balance (survival mode).

🔹 Phase 2: Mid Game (Rounds 9–16)

Goal: Increased competition expected → more aggressive play.

Compared to early rounds:

Uses higher multipliers:

0.6–0.85 × balance

1.6–1.85 × previous average bids

If no_water_days ≥ 2:

Almost always goes near full balance.

This phase prioritizes health stability over saving money.

🔹 Phase 3: End Game (Rounds 17–20)

Goal: Survival > Savings

Rounds 17–18:

Bid 80% of balance

Rounds 19–20:

Bid 100% of balance

At this point, leftover money has no value — survival is everything.

❤️ Health-Based Aggression Model
Health	Strategy
> 7	Conservative
5–7	Moderately aggressive
3–5	Aggressive
< 3	All-in survival
🔁 No-Water Days Escalation
No Water Days	Reaction
0	Conservative
1	Increase bid moderately
2	Highly aggressive
≥3	All-in

This ensures the bot doesn't risk elimination due to dehydration.

📊 Opponent Awareness

From round 2 onwards:

prev_avg_bids = sum_of_previous_bids / 5;

The bot uses:

max(balance_percentage, multiplier × prev_avg_bids)

This prevents being consistently outbid by aggressive players.

🎲 Randomization

The bot uses:

uniform_int_distribution<>(1,10)

Random noise is added to bids to:

Prevent predictability

Avoid being exploited

Simulate human-like bidding behavior

🏗 Structure of Code
Struct Used
struct Player {
    int id;
    string name;
    int water_req;
    int salary;
    int health;
    int balance;
    int no_water_days;
};
Core Steps Per Round

Read water supply.

Read player health & balances.

Read previous bids (if round ≥ 2).

Identify self player.

Apply phase + health logic.

Clamp bid using:

min(balance, computed_value)

Output integer bid.

🛡 Safety Mechanisms

Never bids more than balance.

Switches to full-balance survival when health critical.

Adjusts aggression based on game stage.

🚀 Key Design Philosophy

This bot balances:

💰 Economic efficiency (early game saving)

⚔ Competitive adaptation (uses average bid)

❤️ Survival priority (health-based escalation)

🎲 Unpredictability (random variation)
