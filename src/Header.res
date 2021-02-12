let todosReducer = ((completed, total, bonus), todo: TodoItem.t) =>
  switch (todo.completed, todo.category == Bonus) {
  | (true, true) => (completed, total, bonus +. 1.)
  | (true, false) => (completed +. 1., total +. 1., bonus)
  | (false, _) => (completed, total +. 1., bonus)
  }


@react.component
let make = (~todos: array<TodoItem.t>) => {
  let (percentDone, canPlayGames, bonusTime) = React.useMemo1(() => {
    let (completed, total, bonus) = todos->Belt.Array.reduce((0., 0., 0.), todosReducer)
    let percentage = floor(completed /. total *. 100.)
    let percentDone = percentage->int_of_float
    let canPlayGames = percentDone >= 100
    let bonusTime = bonus->int_of_float * Config.minutesPerBonusTask

    (percentDone, canPlayGames, bonusTime)
  }, [todos])

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
