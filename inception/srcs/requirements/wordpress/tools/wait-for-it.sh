

#!/bin/bash
set -e

host="$1"
shift
cmd="$@"

until nc -z "$host" 3306; do
  >&2 echo "Waiting for MariaDB to be ready..."
  sleep 1
done

>&2 echo "MariaDB is up - executing command"
exec $cmd
