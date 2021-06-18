﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Dal.genericRepository.Abstract;
using entities.Concrete;
namespace Dal.Abstract
{
    public interface IEmanettekiKitaplarDal : IRepositoryBase<emanettekiKitaplar>
    {
        List<emanettekiKitaplar> getAllByStudentId(int studentId);
    }
}