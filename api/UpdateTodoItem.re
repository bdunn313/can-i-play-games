type query = { 
  id: option(string), 
  title: option(string), 
  category: option(string), 
  completed: option(string) 
};
type request = {
  query
};
type data = { item: TodoItem.t };
type jsonResponse = { status: int,  message: string, data: option(data) };
type response = {
  status: int => response,
  json: jsonResponse => unit
};
let makeNewItem = (query: query): TodoItem.t => {
  {
    id: Belt.Option.mapWithDefault(query.id, 0, x => int_of_string(x)),
    title: Belt.Option.getWithDefault(query.title, "New title"),
    category: Belt.Option.mapWithDefault(query.category, TodoItem.Personal, x => switch(x) {
      | "Personal" => TodoItem.Personal
      | "Shared" => TodoItem.Shared
      | "Bonus" => TodoItem.Bonus
      | _ => TodoItem.Personal
    }),
    completed: Belt.Option.mapWithDefault(query.completed, false, x => if (x == "true") {true} else {false}),
  };
};
let default = (req: request, res: response) => {
  let { id } = req.query;
  switch(id) {
    | Some(x) => res.status(200).json({ 
        status: 200, 
        message: "Updated successfully", 
        data: Some({ item: makeNewItem(req.query) }) 
      })
    | None => res.status(400).json({ 
        status: 400, 
        message: "Bad Request", 
        data: None 
      })
  };
};