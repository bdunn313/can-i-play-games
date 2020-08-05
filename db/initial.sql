CREATE TABLE "public"."users" (
    user_id SERIAL PRIMARY KEY NOT NULL,
    name VARCHAR(255) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    created TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT NOW()
);

CREATE TABLE "public"."groups" (
    group_id SERIAL PRIMARY KEY NOT NULL,
    name VARCHAR(255) NOT NULL,
    created TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT NOW()
);

CREATE TABLE "public"."roles" (
    role_id SERIAL PRIMARY KEY NOT NULL,
    name VARCHAR(255) UNIQUE NOT NULL,
    created TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT NOW()
);

ALTER TABLE "public"."users"
ADD COLUMN group_id INTEGER NOT NULL references "public"."groups"(group_id),
ADD COLUMN role_id INTEGER NOT NULL references "public"."roles"(role_id);

CREATE TABLE "public"."categories" (
    category_id SERIAL PRIMARY KEY NOT NULL,
    name VARCHAR(255) UNIQUE NOT NULL,
    created TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT NOW()
);

CREATE TABLE "public"."tasks" (
    task_id SERIAL PRIMARY KEY NOT NULL,
    category_id INTEGER NOT NULL references "public"."categories"(category_id),
    group_id INTEGER NOT NULL references "public"."groups"(group_id),
    user_id INTEGER references "public"."users"(user_id),
    title VARCHAR(255) NOT NULL,
    created TIMESTAMP WITH TIME ZONE NOT NULL DEFAULT NOW()
);