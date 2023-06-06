select people.name from people
join stars on stars.person_id = people.id
join movies on stars.movie_id = movies.id
where movies.id in
(select movies.id from movies join people on stars.person_id = people.id join stars on stars.movie_id = movies.id
where people.birth = 1958 and people.name = "Kevin Bacon")
and people.name != "Kevin Bacon";