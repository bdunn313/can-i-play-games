@react.component
let make = (~label, ~value, ~signed=false) => {
  let sign = React.useMemo1(() => signed && value >= 0 ? "+" : "", [signed])
  <div className=%tw("flex flex-col justify-around items-center relative")>
    <div className=%tw("text-4xl")> {sign ++ string_of_int(value) |> React.string} </div>
    <div className=%tw("text-lg uppercase")> {label |> React.string} </div>
  </div>
}
