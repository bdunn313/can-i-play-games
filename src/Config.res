type env = {"ROLLBAR_TOKEN": string, "NODE_ENV": string}

@val external rollbarToken: string = "process.env.ROLLBAR_TOKEN"
@val external nodeEnv: string = "process.env.NODE_ENV"
let isDev = nodeEnv != "production"

let baseGameMinutes = 90
let maxMinutesPerSession = 30
let minutesPerBonusTask = 10
