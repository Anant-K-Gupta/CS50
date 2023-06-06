-- Keep a log of any SQL queries you execute as you solve the mystery.

--To get the crime_scene_report, found 2 results. We are concerend with the theft of CS50 duck.
SELECT * FROM crime_scene_reports
WHERE street = "Humphrey Street"
AND month = 7 AND day = 28;

--To get the interviews for the crimes.
SELECT * FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE ("%bakery%");

-- Get table of relevant atm transactions
select * from atm_transactions
where year = 2021 and month = 7 and day = 28
and atm_location = "Leggett Street"
and transaction_type = "withdraw";

-- create table with names all all the people who are a suspect due to atm withdrawls
create table atm_suspects as
select name from atm_transactions as atm
join bank_accounts on atm.account_number = bank_accounts.account_number
join people on bank_accounts.person_id = people.id
where year = 2021 and month = 7 and day = 28
and atm_location = "Leggett Street"
and transaction_type = "withdraw";

--finding Fiftyvilles airport details
select * from airports where city = "Fiftyville";

-- get the flights the theif could have taken, earliest flight out is to new york (flight id - 36)
select flights.id, city, flights.hour, flights.minute from flights
join airports on airports.id = flights.destination_airport_id
where flights.origin_airport_id = 8 and
year = 2021 and month = 7 and day = 29
order by flights.hour, flights.minute;

-- create table of all people who were on first flight to new york
create table flight_suspects as
select name from passengers
join people on passengers.passport_number = people.passport_number
where flight_id = 36;

-- create table of all people who made a call for less than 60 sec on that day
create table phone_suspects as
select name from phone_calls
join people on phone_number = caller
where year = 2021 and month = 7 and day = 28
and duration<60;

-- create table of all people who exited parking within time-frame
create table parking_suspects as
select name from people
join bakery_security_logs
on people.license_plate = bakery_security_logs.license_plate
where year = 2021 and month = 7 and day = 28
and activity = 'exit'
and hour = 10 and minute >= 15 and minute <= 25;

-- find common person from all suspect lists
select * from atm_suspects intersect select * from flight_suspects intersect select * from phone_suspects intersect select * from parking_suspects;

-- The common name across all lists is Bruce, thus he is our theif!

-- Getting Bruces details
select * from people where name = 'Bruce';

--+--------+-------+----------------+-----------------+---------------+
--|   id   | name  |  phone_number  | passport_number | license_plate |
--+--------+-------+----------------+-----------------+---------------+
--| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
--+--------+-------+----------------+-----------------+---------------+

-- get accomplice from call log
select name from phone_calls
join people on phone_number = receiver
where caller = '(367) 555-5533'
and year = 2021 and month = 7 and day = 28
and duration<60;
-- accomplice is Robin!

--figuring out the flight bruce took
select * from passengers where passport_number = 5773159633;
-- flight id is 36

select full_name, city from flights
join airports on destination_airport_id = airports.id
where flights.id = 36;

-- flight went to LaGuardia Airport in New York City. Thats where Bruce must have fled to.