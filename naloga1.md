# Naloga 1

![Docker kontejner](docker.png)

```bash
docker pull ghcr.io/mytja/ptr2023/naloga1
```

Uživajte v cca. 300 MB Docker kontejnerja!

Vsebina Dockerfila:
```
FROM alpine:latest as builder

COPY . /app

WORKDIR /app

# Add gcc
RUN apk add build-base

RUN g++ -o naloga1 naloga1.cpp

CMD [ "./naloga1" ]
```