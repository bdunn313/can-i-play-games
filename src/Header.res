@react.component
let make = (~todos: array<TodoItem.t>) => {
  let percentDone = React.useMemo1(() => {
    let nonBonus = Belt.Array.keep(todos, x => x.category != Bonus)
    let completed = Belt.Array.keep(nonBonus, x => x.completed)->Belt.Array.length
    let total = Belt.Array.length(nonBonus)
    let percentage = floor(float_of_int(completed) /. float_of_int(total) *. 100.)
    int_of_float(percentage)
  }, [todos])
  let canPlayGames = React.useMemo1(() => percentDone >= 100, [percentDone])
  let bonusTime = React.useMemo1(
    () =>
      Belt.Array.keep(todos, x => x.completed && x.category == Bonus)
      ->Belt.Array.length
      ->\"*"(Config.minutesPerBonusTask),
    [todos],
  )
  let wrapperClasses = React.useMemo1(() => {
    open Cn
    %tw("flex flex-col justify-center items-stretch")
    ->append(%tw("bg-yellow-300 text-yellow-800")->on(!canPlayGames))
    ->append(%tw("bg-green-300 text-green-800")->on(canPlayGames))
  }, [canPlayGames])
  <header className=wrapperClasses>
    <section className=%tw("flex flex-col justify-center items-center pt-16 uppercase")>
      <LockIcon locked={!canPlayGames} size=100 />
      {(canPlayGames ? "Game on" : "No games") |> React.string}
    </section>
    <section className=%tw("flex flex-row justify-around pb-4")>
      <Metric value=Config.baseGameMinutes label="min" />
      <Metric value=bonusTime label="bonus" signed=true />
    </section>
    <ProgressBar
      percent=percentDone
      variant={
        open ProgressBar
        canPlayGames ? Green : Yellow
      }
    />
  </header>
}
