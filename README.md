# Can I Play Games?

Help the kids know when they've done what they need to do today, so they can play games

## Run Project

```sh
yarn install
yarn start
# in another tab
yarn run webpack
```

After you see the webpack compilation succeed (the `yarn run webpack` step), open up `build/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

## Run Project with Server

To run with the webpack development server run `yarn run server` and view in the browser at http://localhost:8000. Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.

Note that any hot reload on a route will fall back to the root (`/`), so `ReasonReact.Router.dangerouslyGetInitialUrl` will likely be needed alongside the `ReasonReact.Router.watchUrl` logic to handle routing correctly on hot reload refreshes or simply opening the app at a URL that is not the root.

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 yarn run server`).

## Build for Production

```sh
yarn run clean
yarn run build
yarn run webpack:production
```
