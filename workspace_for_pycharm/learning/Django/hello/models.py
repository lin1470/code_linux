# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models

# Create your models here.
from django.db import models

class BlogPost(models.Model):
    title = models.CharField(max_length=150)
    body = models.TestField()
    timestamp = models.DateTimeField()