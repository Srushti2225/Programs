
# Use official Python image
FROM python:3.9-slim

# Set working directory
WORKDIR /app

# Copy requirements file
COPY requirements.txt requirements.txt

# Install dependencies
RUN pip install -r requirements.txt

# Copy application files
COPY . .

# Run Flask application
CMD ["python", "app.py"]
