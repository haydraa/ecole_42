# pull official base image
FROM python:3.11.4-slim-buster

# set work directory
WORKDIR /usr/src/app

# set environment variables
ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1

# install system dependencies
RUN apt-get update \
    && apt-get install -y libpq-dev gcc

RUN apt-get update && apt-get install -y netcat

RUN apt-get update && apt-get install -y postgresql-client

# install dependencies
COPY ./requirements.txt .
RUN pip install --upgrade pip \
    && pip install -r requirements.txt

# copy entrypoint.sh
COPY ./entrypoint.sh .
RUN sed -i 's/\r$//g' /usr/src/app/entrypoint.sh
RUN chmod +x /usr/src/app/entrypoint.sh

# copy project
COPY . .

ENTRYPOINT ["/usr/src/app/entrypoint.sh"]