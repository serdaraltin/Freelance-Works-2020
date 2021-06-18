using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Dal.genericRepository.Abstract
{
    public interface IRepositoryBase<T> where T:class
    {
       List< T> getAll(Expression<Func<T,bool>> filter = null);
        T getOne(Expression<Func<T,bool>> filter);
        void Update(T entity);
        void Add(T entity);
        void Delete(T entity);
    }
}
