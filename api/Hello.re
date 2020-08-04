type query = { name: option(string) };
type request = {
  query
};
type response = {
  status: int => response,
  send: string => unit
};
let default = (req: request, res: response) => {
  let { name } = req.query;
  res.status(200).send(switch(name){
    | Some(x) => {j|Hello $x!|j}
    | None => "Hello World!"
  });
};