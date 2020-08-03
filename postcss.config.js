const purgecss = require("@fullhuman/postcss-purgecss")({
  // Specify the paths to all ReasonML code where you're using this PPX.
  content: ["./src/**/*.re"],

  // Include the extractor from this package
  defaultExtractor: require("@dylanirlbeck/tailwind-ppx").extractor,

  // Ensure some styles make it through
  options: {
    whitelist: ["bg-gray-300", "m-0"]
  }
});

module.exports = {
  plugins: [
    require("postcss-import"),
    require("tailwindcss"),
    require("autoprefixer"),
    ...(process.env.NODE_ENV === "production" ? [purgecss] : []),
  ],
};
